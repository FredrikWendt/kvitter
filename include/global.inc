<?php 
/*
 * Global settings.
 */

session_start();
header("content-type: application/javascript; charset: UTF-8");

$debug = false;

if ($debug) {
	ini_set('display_errors', true);
}

function json_error($message) {
	print json_encode(array("status" => false, "message" => $message));
	exit;
}

?>