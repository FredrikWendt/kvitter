<?php

session_start();

print json_encode(session_destroy());

?>