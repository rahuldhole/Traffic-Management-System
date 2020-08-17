<?php
if(count($_POST)>0){
        $con = mysqli_connect("localhost", "inventme_kismat", "Kismat@30") OR DIE (mysqli_error());
        mysqli_select_db ($con, "inventme_tms") OR DIE ("Unable to select db".mysqli_error());
print_r($_POST);
				if(isset($_FILES['file'])) {
        $name=$_POST['image_name'];
        $fp=addslashes(file_get_contents($_FILES['file']['tmp_name'])); //will store the image to fp
        }
                // our sql query
				$dat = "".date("Y-d-m h:i:s");
				echo $dat;
                //$sql = "INSERT INTO images VALUES('null', '{$name}','{$fp}','{$dat}');";
				$sql = "UPDATE `images` SET `image` = '".$_POST["longitude"]."', `lat` = '".$_POST["lattitude"]."', `address` = '".$_POST["address"]."', `time` = '".$_POST["time"]."' WHERE `bus` = '".$_POST["bus"]."' AND `flag` = '".$_POST["flag"]."'";
				//$sql = "UPDATE `images` SET `image` =  '{$fp}', WHERE `name`='{$name}'";
				  mysqli_query($con, $sql) or die("Error in Query insert: " . mysqli_error()); 

}							
?>
