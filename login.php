<?php

require_once 'include/authentication.inc';
require_once 'include/database.inc';
require_once 'include/global.inc';

$connection = connect_to_db();

$username = get_clean_parameter($connection, "username");
$password = get_clean_parameter($connection, "password");

$result = authenticate($connection, $username, $password); 

print json_encode($result);

?>