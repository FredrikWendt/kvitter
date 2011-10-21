<?php

require_once 'include/authentication.inc';
require_once 'include/database.inc';
require_once 'include/global.inc';
require_once 'include/tweets.inc';

user_must_be_logged_in();

$myconnection = connect_to_db();

$user_id = get_user_id();

print json_encode(get_tweet_feed_from_friends($myconnection, $user_id));

mysqli_close($myconnection);

?>