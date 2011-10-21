<?php 
/*
 * Things related to database tables.
 */

/**
 * Connects to the default database and returns the connection link.
 */
function connect_to_db() {
	$connection = mysqli_connect("dyn.wendt.se", "dynXXX11", "dynXXX11", "dynXXX11");
	$result = mysqli_query($connection, "SET NAMES 'utf8';");
	return $connection;
}

/**
 * Cleans up the $data from SQL injections attacks.
 */
function clean_up($connect, $data) {
	// FIXME: SQL injection protection
	return $data;
}

/**
 * Returns the cleaned up parameter value.
 * @param MYSQLI $connect connection to MySQL database
 * @param string $parameter_name name of the parameter to get
 */
function get_clean_parameter($connect, $parameter_name) {
	return clean_up($connect, $_REQUEST[$parameter_name]);
}
?>
