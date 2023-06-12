<!DOCTYPE html>

<html>
    <head>
        <meta charset="UTF-8">
        <title>Survey Application</title>
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
        <div id='login-form'>
            <h3>Login</h3>
            <form action="creator_log_in.php" method="post"> 
                <label for="username">Username:</label>
                <input type="text" name="username" id="username">
                <label for="password">Password:</label>
                <input type="password" name="password" id="password">
                <input type="hidden" name="user_login">
                <input type="submit" value="LOGIN!">
            </form>
        </div>
        <?php
        require_once 'login.php';
        $conn = new mysqli($hn, $un, $pw, $db);
        if ($conn->connect_error)
            die($conn->connect_error);

        if(isset($_POST['user_login'])){
            $username = sanitizeInput($conn, 'username'); 
            $password = sanitizeInput($conn, 'password');

            //Use prepared statements to prevent SQL Injection
            $stmt = $conn->prepare("SELECT * FROM user_creator WHERE username=? AND password=?");
            $stmt->bind_param("ss", $username, $password);
            $stmt->execute();
            $result = $stmt->get_result();
            if($result->num_rows === 0){
                echo "There is no account in the database with those credentials <br>"; 
            } else {
                session_start(); 
                $_SESSION['username'] = $username;

                $stmt2 = $conn->prepare("SELECT survey_num FROM user_creator WHERE username=?");
                $stmt2->bind_param("s", $username);
                $stmt2->execute();
                $result2 = $stmt2->get_result();
                $temp = $result2->fetch_array();
                $survey_num_holder = $temp[0];

                $stmt3 = $conn->prepare("SELECT * FROM survey_ans WHERE survey_num=?");
                $stmt3->bind_param("s", $survey_num_holder);
                $stmt3->execute();
                $result3 = $stmt3->get_result();
                if($result3->num_rows === 0){
                    echo "There's nothing to show <br>"; 
                } else {
                    echo "<table>";
                    while($row = $result3->fetch_array(MYSQLI_NUM)){
                        echo "<tr>";
                        echo "<td> Question 1 " .$row[1] . "</tr>"; 
                        echo "<td> Question 2 " . $row[2] . "</tr>";
                        echo "<td> Question 3 " . $row[3] . "</tr>";
                        echo "</tr>"; 
                    }
                    echo "</table>"; 
                }
            }
        }

        function sanitizeInput($conn, $var) {
            return $conn->real_escape_string($_POST[$var]);
        }
        ?>
    </body>
</html>
