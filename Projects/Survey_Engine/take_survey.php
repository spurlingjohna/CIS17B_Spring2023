<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Take a Survey</title>
        <link rel="stylesheet" type="text/css" href="style.css">
    </head>
    <body>
        <header>
            <a href='index.php'><img src="survey.png" height="100" width="100"></a>
        </header>

        <nav>
            <ul>
                <li class="selected"><a href="take_survey.php">Take Survey</a></li>
                <li><a href="creator_register.php">Create a Survey</a></li>
                <li><a href="creator_log_in.php">See Survey Response</a></li>
            </ul>
        </nav>

        <div id='list'>
            <h3>
                <form action="take_survey.php" method="post">
                    <label for="survey_num">Survey Number:</label>
                    <input type="text" id="survey_num" name="survey_num">
                    <input type="hidden" name="survey">
                    <input type="submit" value="Take the survey">
                </form>
            </h3>
        </div>

        <?php
        require_once 'login.php';

        $conn = new mysqli($hn, $un, $pw, $db);
        if ($conn->connect_error) die("Fatal Error");

        if (isset($_POST['record_survey'])) {
            recordSurvey($conn);
        }

        if (isset($_POST['survey'])) {
            handleSurvey($conn);
        }

        function get_post($conn, $var) {
            return $conn->real_escape_string($_POST[$var]);
        }

        function recordSurvey($conn) {
            $q1 = get_post($conn, 'q1');
            $q2 = get_post($conn, 'q2');
            $q3 = get_post($conn, 'q3');
            $query2 = "INSERT INTO survey_ans VALUES ('$survey_num','$q1','$q2','$q3')";
            $result2 = $conn->query($query2);
            echo $result2 ? "It worked! <br>" : "Damnit <br>";
        }

        function handleSurvey($conn) {
            $survey_num = get_post($conn, 'survey_num');
            $query = "select count(*) from user_creator where survey_num = '$survey_num'";
            $result = $conn->query($query);
            $count = mysqli_fetch_array($result);

            if ($count[0] == 0) {
                echo "<div id='list'>There isn't a survey attached to that number <br></div>";
            } elseif ($count[0] > 0) {
                $query1 = "SELECT * FROM user_creator where survey_num = 'survey_num'";
                $result1 = $conn->query($query1);

                if (!$result1) {
                    echo "No such survey exists, try another number <br>";
                } else {
                    session_start();
                    $_SESSION['survey_num'] = $survey_num;
                    header('location:survey_response.php');
                }
            }
        }
        ?>
    </body>
</html>
