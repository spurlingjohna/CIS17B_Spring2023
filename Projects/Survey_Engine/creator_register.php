<!DOCTYPE html>

<html>
    <head>
        <meta charset="UTF-8">
        <title>Survey Creator Registration</title>
        <link rel="stylesheet" type="text/css" href="style.css">
    </head>
    <body>
        <header>
            <a href='index.php'><img src="survey.png" height=100 width=100 alt="Survey"></a>
        </header>
        <nav>
            <ul>
                <li class="selected"><a href="take_survey.php">Take Survey</a></li>
                <li><a href="creator_register.php">Create a Survey</a></li>
                <li><a href="creator_log_in.php">See Survey Response</a></li>
            </ul>
        </nav>
        <div id='registration-form'>
            <h3>Register</h3>
            <form action="creator_register.php" method="post">
                <label for="username">Username:</label>
                <input type="text" name="username" id="username">
                <label for="password">Password:</label>
                <input type="password" name="password" id="password" pattern="^.{4,8}$">
                <label for="q1">Question #1:</label>
                <input type="text" name="q1" id="q1">
                <label for="q2">Question #2:</label>
                <input type="text" name="q2" id="q2">
                <label for="q3">Question #3:</label>
                <input type="text" name="q3" id="q3">
                <input type="hidden" name="create_user">
                <input type="submit" value="REGISTER">
            </form>
        </div>
        <?php
        require_once 'login.php';

        $conn = new mysqli($hn, $un, $pw, $db);
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }
        $query = "SELECT COUNT(*) as count FROM user_creator";
        $result = $conn->query($query);
        if (!$result) {
            echo "Something went wrong!";
        }
        $count = $result->fetch_assoc();
        $survey_num = $count['count'] + 10238;

        if (isset($_POST['create_user'])) {
            $username = sanitizeInput($conn, 'username');
            $password = sanitizeInput($conn, 'password');
            $q1 = sanitizeInput($conn, 'q1');
            $q2 = sanitizeInput($conn, 'q2');
            $q3 = sanitizeInput($conn, 'q3');

            //Use prepared statements to prevent SQL Injection
            $stmt = $conn->prepare("INSERT INTO user_creator (username, password, q1, q2, q3, survey_num) VALUES (?, ?, ?, ?, ?, ?)");
            $stmt->bind_param("sssssi", $username, $password, $q1, $q2, $q3, $survey_num);
            $stmt->execute();

            if ($stmt->affected_rows === 0) {
                echo "<h3>The Username you entered is already taken, try another <br></h3>";
            } else {
                echo "<h2>Your survey number is " . $survey_num . "</h2>";
            }
        }

        function sanitizeInput($conn, $var) {
            return $conn->real_escape_string($_POST[$var]);
        }
        ?>
    </body>
</html>
