<?php

session_start();
if(!isset($_SESSION['username']))  
{
header('location:index.php');
}
unset($_SESSION['username']);    
session_destroy();                  
header('location:index.php');
?>

