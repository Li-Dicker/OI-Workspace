<html>
	<body>
		<form method="post" action="<?php echo $_SERVER['PHP_SELF'];?>">
			Name:<input type="text" name="fname">
			<input type="submit" name="submition">
		</form>
		<?php
			$name=$_REQUEST['fname'];
			$submission=$_REQUEST['submition'];
			echo $submission;
			echo 
		?>
	</body>
</html>