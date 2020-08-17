<?php  session_start(); if(!isset($_SESSION["id"])) { header("Location: ../index.php"); }  ?>
			
<h1>Upload a new photo</h1>
			<form action="" method="post"  enctype="multipart/form-data">
<input type="hidden" name="image_name" id="" value = "uploaded" />
<input type = "hidden" value = "<?php echo $_GET["id"]; ?>" name = "id">
<input name="image" id="image" accept="image/JPEG" type="file">
<input type="submit" value="submit" name="submit" />
</form>


<?php
if(count($_POST)>0){
include_once("../db.php");	
//print_r($_POST);
		
		if(isset($_FILES['image'])) {
        $name=$_POST['image_name'];
        $fp=addslashes(file_get_contents($_FILES['image']['tmp_name'])); //will store the image to fp
        }
			 $id = $_POST["id"];
	  // $sql = "UPDATE defaulters SET photo =  '".$fp."' WHERE id='".$id."'";
	   $sql = "UPDATE `defaulters` SET `photo` =  '{$fp}' WHERE `id`='{$id}'";
				mysqli_query($conn, $sql) or die("Error in Query insert: " . mysqli_error());  
	  
		}		
				?>
				
