/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHP.php to edit this template
 */

<?php
session_start();

if(!isset($_SESSION['username'])) {
    // If session not found, redirect to homepage.
    header('location:index.php');
    exit;
}

// If session found, unset the variable values.
unset($_SESSION['username']);

// Destroy the session.
session_destroy();

// Redirect to index page.
header('location:index.php');
exit;
?>
