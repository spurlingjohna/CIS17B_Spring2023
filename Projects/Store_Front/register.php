/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHP.php to edit this template
 */

<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>User Registration</title>
        <link rel="stylesheet" type="text/css" href="style.css">
    </head>
    <header>
        <img src='assets/icon.png' height=100px width=100px>
    </header>
    <body>
        <?php
        session_start();
        $navLogged = <<<NAVLOGGED
        <nav>
            <ul>
                <li><a href="index.php">Home</a></li>
                <li><a href="cart.php">Cart</a></li>
                <li><a href="logout.php">Logoff</a></li>
                <li><a href="sqltest.php">Admin</a></li>
            </ul>
        </nav>
NAVLOGGED;

        $navGuest = <<<NAVGUEST
        <nav>
            <ul>
                <li class="selected"><a href="index.php">Home</a></li>
                <li><a href="cart.php">Cart</a></li>
                <li><a href="register.php">Register</a></li>
                <li><a href="user_login.php">Login</a></li>
            </ul>
        </nav>
NAVGUEST;

        echo isset($_SESSION['username']) ? $navLogged : $navGuest;
        ?>

        <form action="register.php" method="post"><pre>
            Name <input type="text" name="name">
            Age <input type="text" name="age" pattern="^\d+(,\d{1,2})?$">
            Username <input type="text" name="username">
            Password <input type="password" name="password" pattern="^.{4,8}$">
            Address <input type="text" name="address">
            <input type="hidden" name="create_account" value="yes">
            <input type="submit" value="create account">
        </pre></form>

        <?php
        require_once 'login.php';
        $databaseConnection = new mysqli($hn, $un, $pw, $db);

        if ($databaseConnection->connect_error) {
            die($databaseConnection->connect_error);
        }

        if (isset($_POST['create_account'])) {
            $user_name = sanitize_input($databaseConnection, 'name');
            $user_age = sanitize_input($databaseConnection, 'age');
            $user_username = sanitize_input($databaseConnection, 'username');
            $user_password = sanitize_input($databaseConnection, 'password');
            $user_address = sanitize_input($databaseConnection, 'address');

            $query = "INSERT INTO customers VALUES ('$user_name', '$user_age', '$user_username', '$user_password', '$user_address')";
            $queryResult = $databaseConnection->query($query);

            if (!$queryResult) {
                echo "That username is already taken, try another<br>";
            } else {
                header('location:index.php');
            }
        }

        function sanitize_input($databaseConnection, $input) {
            return $databaseConnection->real_escape_string($_POST[$input]);
        }
        ?>
    </body>
</html>
