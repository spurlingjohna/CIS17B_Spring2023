<?php
session_start();
require_once 'login.php';
$conn = new mysqli($hn, $un, $pw, $db);

$loggedInUser = isset($_SESSION['username']);
$customer_id = $loggedInUser ? $_SESSION['username'] : '0';

if ($conn->connect_error)
    die("Fatal Error");

if (!$loggedInUser) {
    $query = "DELETE FROM cart where customer_id='0'";
    $conn->query($query);
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>It's a store</title>
    <link type="text/css" rel="stylesheet" href="style.css">
</head>
<body>
<header>
    <img src='assets/icon.png' height=100px width=100px>
</header>

<?php
if ($loggedInUser) {
    include 'loggedInNavBar.php';
} else {
    include 'guestNavBar.php';
}

if (isset($_POST['add_to_cart'])) {

    $sku = get_post($conn, 'sku');
    $quantity = get_post($conn, 'quantity');
    $name = get_post($conn, 'name');
    $price = get_post($conn, 'price');

    $query = "INSERT INTO cart VALUES ('$sku','$name', '$price', '$quantity','$customer_id')";
    $result = $conn->query($query);
    if (!$result) {
        echo "INSERT failed: $query<br>" . mysqli_error($conn) . "<br><br>";
    }
}

function get_post($conn, $var) {
    return $conn->real_escape_string($_POST[$var]);
}

$query = "SELECT * FROM items";
$result = $conn->query($query);
if (!$result) die("Fatal Error");

$rows = $result->num_rows;
if ($rows === 0) {
    echo "There's no items to show";
} else {
    for ($j = 0; $j < $rows; ++$j) {
        $result->data_seek($j);
        $row = $result->fetch_array(MYSQLI_NUM);
        
        include 'itemDetails.php';
    }
}
$result->close();
$conn->close();
?>

</body>
</html>
