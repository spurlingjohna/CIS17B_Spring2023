<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>User Registration</title>
    </head>
    <body>
        <form action="user_register.php" method="post">
            <label for="username">Username:</label>
            <input type="text" id="username" name="username">
            
            <label for="password">Password:</label>
            <input type="password" id="password" name="password">
            
            <input type="hidden" name="create_user">
            <input type="submit" value="REGISTER!">
        </form>

        <?php
        require_once 'login.php';

        $conn = new mysqli($hn, $un, $pw, $db);
        if ($conn->connect_error) die("Fatal Error");

        if (isset($_POST['create_user'])) {
            $username = sanitizeInput($conn, 'username');
            $password = sanitizeInput($conn, 'password');
            
            $query = "INSERT INTO user_survey_user VALUES ('$username', '$password')";
            $result = $conn->query($query);
            
            if (!$result) {
                echo "Oops, something went wrong <br>";
            }
        }

        function sanitizeInput($conn, $var) {
            return $conn->real_escape_string($_POST[$var]);
        }
        ?>
    </body>
</html>
