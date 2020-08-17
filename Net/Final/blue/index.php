<html> 
<head> 
  <title>Traffic Management System</title> 
  <meta name="viewport" content="width=device-width, initial-scale=1"> 
  <link rel="stylesheet" href="assets/css/jquery.mobile-1.2.0.css" />
  <script src="assets/js/jquery-1.8.2.min.js"></script>
  <script src="assets/js/jquery.mobile-1.2.0.min.js"></script>
</head> 
<body> 

<div data-role="page">

  <div data-role="header">
    <h1><marquee>Traffic Management System</marquee></h1>
  </div><!-- /header -->

  <div data-role="content"> 
<!----Start Content Body---->
<div  align = "center">
<form action ="" method="post">
  <table border = "0">
  <tr>
  <td><input type = "text" placeholder = "Username" name ="uname"></td>
  </tr>
  <tr>
  <td><input type = "password" placeholder = "Password" name ="pass"></td>
  </tr>
   <tr>
  <td><input type = "submit" value = "Login"></td>
  </tr>
  </table>
  </form>
 </div>
  
  
<?php

session_start();
$message="";
if(count($_POST)>0) {
	include_once("db.php");
$result = mysqli_query($conn, "SELECT * FROM users WHERE username='" . $_POST["uname"] . "' and password = '". $_POST["pass"]."'");
//INSERT INTO `a1100935_dbms`.`login` (`mobile`, `password`) VALUES ('9545584590', 'kismat');
$row  = mysqli_fetch_array($result);
if(is_array($row)) {
$_SESSION["id"] = $row["username"];
$_SESSION["name"] = $row["name"];
$_SESSION["type"] = $row["user_type"];
} else {
$message = "Invalid Username or Password!";
}
}
if(isset($_SESSION["id"])) {
header("Location:home.php");
}

?>
  
  
<!----End Content Body---->  
  </div><!-- /content -->

 <!----Footer---->
  <div data-role="footer" data-position="fixed">
    <div data-role="navbar">
    <h4></h4>
	</div>
  </div>

</div><!-- /page -->

</body>
</html>
