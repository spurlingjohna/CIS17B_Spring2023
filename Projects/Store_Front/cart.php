/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHP.php to edit this template
 */

<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Shopping Page</title>
        <link rel="stylesheet" type="text/css" href="style.css">
    </head>
    <header><img src='assets/icon.png' height=100px width=100px></header>
    <body>
        <?php
        require_once "login.php";
        session_start(); 

        $loggedInUser = isset($_SESSION['username']);
        $currentUserID = $loggedInUser ? $_SESSION['username'] : '0';
        
        $conn = new mysqli($hn, $un, $pw, $db);
        if ($conn->connect_error) die($conn->connect_error);
        
        if ($loggedInUser) {
            include 'loggedInNavBar.php';
        } else {
            include 'guestNavBar.php';
            echo "You're not logged in <br>";
        }
        
        if (isset($_POST['delete'], $_POST['sku'])) {
            $sku = $conn->real_escape_string($_POST['sku']);
            $query = "DELETE FROM cart WHERE sku='$sku' and customer_id = '$currentUserID'";

            $result = $conn->query($query);
            if (!$result) echo "DELETE failed: $query<br>" . $conn->error . "<br><br>";
        }

        $query = "SELECT * FROM cart where customer_id = '$currentUserID'";
        $result = $conn->query($query);
        if (!$result) die("Fatal Error");

        $rows = $result->num_rows;
        $totalPrice = 0;

        for ($j = 0; $j < $rows; ++$j) {
            $result->data_seek($j);
            $row = $result->fetch_array(MYSQLI_NUM);
            $skuTemp = $row[0];

            echo "SKU $row[0] <br>";
            echo "Name $row[1] <br>";
            echo "Price $row[2]<br>";
            echo "quantity $row[3] <br>";

            $totalPrice += ($row[2] * $row[3]);
            
            include 'orderAndDeleteForm.php';
        }

        echo "The value of everything in your cart is: $" . ($totalPrice / 100) . "<br>";

        if(isset($_POST['submit_order'])){
            $sku = get_post($conn, 'sku'); 
            $quantity = get_post($conn, 'quantity'); 

            $query = "INSERT INTO orders_placed VALUES ('$currentUserID','$sku','$quantity')";
            $result = $conn->query($query); 
            if(!$result) die;

            header('location:placed.php'); 
        }

        function get_post($conn, $var) {
            return $conn->real_escape_string($_POST[$var]);
        }
        ?>
    </body>
</html>
