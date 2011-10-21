<?php

require_once 'include/database.inc';
require_once 'include/global.inc';
require_once 'include/profile.inc';

$myconnection = connect_to_db();

$username = get_clean_parameter($myconnection, "username");
$password = get_clean_parameter($myconnection, "password");
$name = get_clean_parameter($myconnection, "name");
$email = get_clean_parameter($myconnection, "email");

print json_encode(register_new_profile($myconnection, $username, $password, $name, $email));

mysqli_close($myconnection);

?>