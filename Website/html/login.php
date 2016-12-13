<?php

session_start();

ini_set('include_path', ini_get('include_path') . ':../includes');
require_once 'Page.class.php';

if (isset($_GET['lang'])){
	$lang = 'pt';
	if ($_GET['lang'] == 'pt') $lang = 'pt';
	if ($_GET['lang'] == 'en') $lang = 'en';
	$_SESSION["DEI_Lang"] = $lang;
} elseif (isset($_SESSION["DEI_Lang"])){
	$lang = $_SESSION["DEI_Lang"];
} else {
	$lang = 'pt';
	$_SESSION["DEI_Lang"] = $lang;
}

$p = new Page('login.html.php', 'DEI Alumni - Register', $lang);
$p->setActiveMenu(0);
$p->show();
?>
