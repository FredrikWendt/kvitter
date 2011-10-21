<?php

require_once 'include/authentication.inc';
require_once 'include/database.inc';
require_once 'include/global.inc';
require_once 'include/tweets.inc';

user_must_be_logged_in();

$myconnection = connect_to_db();

$message = get_clean_parameter($myconnection, "message");

print json_encode(save_tweet($myconnection, $message));

mysqli_close($myconnection);

?>