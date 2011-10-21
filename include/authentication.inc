<?php

/*
 *
 * Functions related to login/authentication.
 *
 */

/**
 * Returns the logged in user's ID (member_id).
 */
function get_user_id() {
	return $_SESSION["id"];
}

/**
 * Returns the logged in user's username.
 */
function get_username() {
	return $_SESSION["username"];
}

/**
 * Makes sure the user is logged in, or the request is redirected to start.html.
 */
function user_must_be_logged_in() {
	if (isset($_SESSION["username"])) {
		return;
	}
	json_error("Unauthorized HTTP request.");
}

/**
 *
 * @param unknown_type $connection
 * @param unknown_type $username
 * @param unknown_type $password
 * @return
 */
function authenticate($connection, $username, $password) {
	$query = "SELECT id FROM members WHERE username LIKE '$username' AND password LIKE '$password';";
	$mresult = mysqli_query($connection, $query);
	if (mysqli_num_rows($mresult) == 0) {
		json_error("Incorrect credentials");
	}
	$row_data = mysqli_fetch_assoc($mresult);
	
	$_SESSION["id"] = $row_data["id"];
	$_SESSION["username"] = $username;
	
	return array(
		"status" => true,
		"username" => $username, 
		"id" => $row_data["id"]);
}

?>