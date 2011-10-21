<?php

require_once 'include/authentication.inc';
require_once 'include/database.inc';
require_once 'include/global.inc';
require_once 'include/tweets.inc';

user_must_be_logged_in();

$myconnection = connect_to_db();

$phrase = get_clean_parameter($myconnection, "q");

print json_encode(get_tweets_containing_phrase($myconnection, $phrase));

mysqli_close($myconnection);

?>