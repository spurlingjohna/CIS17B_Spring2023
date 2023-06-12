/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHP.php to edit this template
 */

<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Admin Dashboard</title>
        <link rel="stylesheet" type="text/css" href="style.css">
    </head>
    <header>
        <img src='assets/icon.png' height=100px width=100px>
    </header>
    <body>
        <?php
        session_start();

        require_once 'login.php';
        $databaseConnection = new mysqli($hn, $un, $pw, $db);

        if ($databaseConnection->connect_error) {
            die($databaseConnection->connect_error);
        }

        $navAdmin = <<<NAVADMIN
        <nav>
            <ul>
                <li><a href="index.php">Home</a></li>
                <li><a href="cart.php">Cart</a></li>
                <li><a href="logout.php">Logoff</a></li>
                <li><a href="sqltest.php">Admin</a></li>
            </ul>
        </nav>
NAVADMIN;

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

        echo (isset($_SESSION['username']) && $_SESSION['username'] == 'admin') ? $navAdmin : $navGuest;

        if (!isset($_SESSION['username']) || ($_SESSION['username'] != 'admin')) {
            header('location:index.php');
        } else {
            echo "Hello " . $_SESSION['username'] . "<br>";
        }

        // Rest of the code
        // You can refactor the rest of the code using similar naming conventions as mentioned above.
        ?>

    </body>
</html>
