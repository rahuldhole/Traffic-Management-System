<?php  session_start(); if(!isset($_SESSION["id"])) { header("Location: ../index.php"); }  ?>
<html> 
<head> 
  <title>Traffic Management System</title> 
  <meta name="viewport" content="width=device-width, initial-scale=1"> 
  <link rel="stylesheet" href="../assets/css/jquery.mobile-1.2.0.css" />
  <script src="../assets/js/jquery-1.8.2.min.js"></script>
  <script src="../assets/js/jquery.mobile-1.2.0.min.js"></script>
</head> 
<body> 

<div data-role="page">

<a href = "../">
  <div data-role="header">
    <h1>Traffic Management System</h1>
  </div><!-- /header -->
</a>

  <div align = "center"> 
<!----Start Content Body---->

  <h1>Signal break from signals</h1>
  
<table border = '0' style = 'color : white' align = 'center'><tr style=
'background:#0193e9 ' style='font-family:Comic Sans MS' align = 'center'>
<td>Signal Name</td><td>Address</td><td>Contact Number</td></tr>
<?php

include_once("../db.php");
$result = mysqli_query($conn, "SELECT * FROM signals");
//INSERT INTO `a1100935_dbms`.`login` (`mobile`, `password`) VALUES ('9545584590', 'kismat');
$row  = mysqli_fetch_array($result);
if(is_array($row)) 
							{
								
								foreach($result as $row)
								{
									echo"<tr style='background:silver' style='font-family:Comic Sans MS' align = 'center'>";
									echo "<td><a href = 'break_at.php?n=0&signo=".$row['signo']."'>".$row['signo']."</a></td>"."<td>".
									$row['address']."</td>"."<td>".
									$row['contact']."</td>"."<td>";
									echo"</tr>";
								}
							} else {
echo "Data not available...";
}

?>  
</table>
  
  
<!----End Content Body---->  
  </div><!-- /content -->

 <!----Footer---->
  <div data-role="footer" data-position="fixed">
    <div data-role="navbar">
      <ul>
        <li><a href="../signals/signals_list.php" data-icon="gear" class="ui-btn-active ui-state-persist">Signals List</a></li>
        <li><a href="signalbreak.php" data-icon="refresh">Signal break</a></li>
        <li><a href="../priority1/priority1.php" data-icon="menu">Priority 1 vehicles</a></li>
		<li><a href="../logout.php"><?php echo "<b>".$_SESSION["name"]."</b>,"; ?>	Logout</a>		</li>
      </ul>
    </div>
  </div>

</div><!-- /page -->

</body>
</html>
