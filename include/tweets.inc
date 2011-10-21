<?php 
/*
 * Things related to tweets.
 */

/**
 * Returns all tweets from the specified user.
 */
function get_tweets_from($myconnection, $username) {
	$myquery = "SELECT m.username, t.* FROM tweets t INNER JOIN members m ON m.id=t.members_id WHERE m.username LIKE '$username' ORDER BY id DESC;";
	
	return _get_tweets($myconnection, $myquery);
}


/**
 * Returns all tweets from all the members that $user_id is following.
 */
function get_tweet_feed_from_friends($connection, $user_id) {
	$query = "SELECT m.username, t.message, t.id ".
	"FROM members m ".
		"INNER JOIN tweets t ON t.members_id=m.id ". 
		"INNER JOIN followers f ON f.members_id=m.id ". 
	"WHERE f.followed_by=$user_id ".
	"ORDER BY t.id DESC;";

	return _get_tweets($connection, $query);
}


function get_tweets_containing_phrase($myconnection, $phrase) {
	$query = "SELECT m.username, t.message, t.id ". 
		"FROM members m INNER JOIN tweets t ON t.members_id=m.id ".
		"WHERE t.message LIKE '%$phrase%' ORDER BY t.id DESC;";
	
	return _get_tweets($myconnection, $query);
}

function save_tweet($myconnection, $message) {
	$user_id = get_user_id();
	$query = "INSERT INTO tweets (members_id, message) VALUES ($user_id, '$message');";
	$myresult = mysqli_query($myconnection, $query);
	return mysqli_affected_rows($myconnection);
}

// ---- _____________________________________________________________________________________________


/**
 * @private 
 * 
 * @param unknown_type $myconnection
 * @param string $myquery a query that contains username, id and message columns, sorted by id DESC.
 */
function _get_tweets($myconnection, $query) {
	$myresult = mysqli_query($myconnection, $query);
	
	$tweets = array();
	while ($row = mysqli_fetch_assoc($myresult)) {
		$tweet = array(
			"time" => $row["id"],
			"message" => $row["message"],
			"username" => $row["username"]
		);
		$tweets[] = $tweet;
	}
	
	mysqli_free_result($myresult);
	
	return array("status" => true, "tweets" => $tweets);
}

?>