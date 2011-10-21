<?php 
/*
 * Things related to profiles.
 */

function get_full_profile($myconnection, $username) {
	$profile = _get_basic_profile($myconnection, $username);
	_decorate_profile_with_followers($myconnection, $profile);
	return array("status" => true, "profile" => $profile);
}

function register_new_profile($myconnection, $username, $password, $name, $email) {
	if ($password == '') {
		json_error("That password is too lame");
	}
	
	if ($email == '') {
		json_error("You need to provide an e-mail address");
	}
	
	if ($username == '') {
		json_error("You need to provide a valid username");
	}
	
	if ($name == '') {
		$name = $username;
	}

	if (_username_is_occupied($myconnection, $username)) {
		json_error("Username $username is used by someone else");
	}
	
	_save_profile($myconnection, $username, $password, $name, $email);
	
	return array("status" => true); 
}

// ---- _____________________________________________________________________________________________


function _decorate_profile_with_followers($myconnection, &$profile) {
	$user_id = $profile["id"];

	$query = "SELECT m.* ".
		"FROM members m INNER JOIN followers f ON f.members_id=m.id ". 
		"WHERE f.followed_by=$user_id ".
		"ORDER BY m.username;";
	$profile["follows"] = _get_minimal_profiles($myconnection, $query);
	
	$query = "SELECT m.* ".
		"FROM members m INNER JOIN followers f ON f.followed_by=m.id ". 
		"WHERE f.members_id=$user_id ".
		"ORDER BY m.name;";
	$profile["followers"] = _get_minimal_profiles($myconnection, $query);
}

function _get_basic_profile($myconnection, $username) {
	$query = "SELECT m.* FROM members m WHERE m.username LIKE '$username';";
	$keys = split(":", "name:username:email:id");
	$profiles = _get_generic_profiles($myconnection, $query, $keys);
	return $profiles[0];
}

function _get_minimal_profiles($myconnection, $query) {
	$keys = split(":", "username:email");
	return _get_generic_profiles($myconnection, $query, $keys);
}

function _get_generic_profiles($myconnection, $query, $keys) {
	$myresult = mysqli_query($myconnection, $query);
	
	$profiles = array();
	while ($row = mysqli_fetch_assoc($myresult)) {
		$profile = array();
		foreach ($keys as $key) {
			$profile[$key] = $row[$key];
		}
		$profiles[] = $profile;
	}
	
	mysqli_free_result($myresult);
	
	return $profiles;
}

function _username_is_occupied($myconnection, $username) {
	$query = "SELECT id FROM members WHERE username LIKE '$username';";
	$result = mysqli_query($myconnection, $query);
	$rows = mysqli_num_rows($result);
	mysqli_free_result($result);
	return $rows > 0;
}

function _save_profile($myconnection, $username, $password, $name, $email){
	$query = "INSERT INTO members (username, password, name, email) VALUES ('$username', '$password', '$name', '$email');";
	mysqli_query($myconnection, $query);
}

?>