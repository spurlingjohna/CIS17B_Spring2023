/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHP.php to edit this template
 */

<?php
session_start();
if (!isset($_SESSION['username'])) {
    header('location:index.php');
    exit;
}

echo "Welcome &nbsp;";
echo $_SESSION['username'];
?>

<html>
    <head>
    </head>
    <body>
    <center>
        <h2>Welcome to Main page</h2>
        <a href="logout.php">Logout</a>
    </center>
</body>
</html>
