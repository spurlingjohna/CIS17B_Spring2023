/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHP.php to edit this template
 */

<?php
session_start();

if (isset($_POST['login_attempt'])) {
    $admin_username = "admin";
    $admin_password = "123";

    if ($_POST['user'] === $admin_username && $_POST['pass'] === $admin_password) {
        $_SESSION['user'] = $admin_username;
        header('location:sqltest.php');
    } else {
        $login_error = "Authentication Failed. Please Try again!";
    }
}
?>

<!DOCTYPE html>
<html>
    <head>
        <title>Login Page</title>
    </head>
    <body>
    <center>
        <?php 
        if (isset($login_error)) {
            echo $login_error;
        }
        ?>

        <form method="POST" name="login_form" target="_self">
            Username: <input name="user" size="20" type="text" />
            <br/><br/>
            Password: <input name="pass" size="20" type="password" />
            <br/><br/>
            <input name="login_attempt" type="submit" value="Log In" />
        </form>
    </center>
</body>
</html>
