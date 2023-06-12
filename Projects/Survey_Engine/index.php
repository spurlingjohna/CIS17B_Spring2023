<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Simple Survey Engine</title>
        <link rel="stylesheet" type="text/css" href="style.css">
    </head>
    <body>
        <header class="header">
            <a href='index.php'><img src="survey.png" height=100 width=100></a>
        </header>
        <nav class="nav">
            <ul>
                <li class="nav__item nav__item--selected"><a class="nav__link" href="take_survey.php">Take Survey</a></li>
                <li class="nav__item"><a class="nav__link" href="creator_register.php">Create a Survey</a></li>
                <li class="nav__item"><a class="nav__link" href="creator_log_in.php">See Survey Response</a></li>
            </ul>
        </nav>
        <h1 class="heading heading--1">This is a simple survey engine</h1>
        <h2 class="heading heading--2">This site has been made so users can create a three question survey for participants to complete. The survey creator can then log in at any time to see what participants have said. </h2>
        <div id='list' class="list">
            <h3 class="heading heading--3">Using this site takes just three easy steps: 
                <ol>
                    <li>Click 'Create a survey' and make an account</li>
                    <li>Send out the survey number and the URL to participants</li>
                    <li>Log back in and see the responses you received </li>
                </ol>
            </h3>
        </div>
        <?php
        if (isset($_SESSION['username'])) {
            echo "You're logged in <br>";
        }
        ?>
    </body>
</html>
