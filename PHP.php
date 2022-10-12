<!DOCTYPE HTML>  
<html>
<head>
<style>
.error {color: #FF0000;}
</style>
</head>
<body>  

<?php
// define variables and set to empty values
$nameErr = $emailErr = $genderErr  = $degreeErr= $BGErr =$DOBErr= "";
$name = $email = $gender  = $degree = $BG =$DOB= "";


if ($_SERVER["REQUEST_METHOD"] == "POST") {
  if (empty($_POST["name"])) {
    $nameErr = "Name is required";
  } else {
    $name = test_input($_POST["name"]);
    // check if name only contains letters and whitespace
    if (!preg_match("/^[a-zA-Z-' ]*$/",$name)) {
      $nameErr = "Only letters and white space allowed";
    }
    if(str_word_count($name) < 2)
    {$nameErr = "Must contain at least 2 words";}
}

  }
  

  if (empty($_POST["email"])) {
    $emailErr = "Email is required";
  } else {
    $email = test_input($_POST["email"]);
    // check if e-mail address is well-formed
    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
      $emailErr = "Invalid email format";
    }
  }

  if (empty($_POST["DOB"])) {
    $DOBErr = "Date of Birth is required";
  } else {
    $DOB = test_input($_POST["DOB"]);
  }

  if (empty($_POST["gender"])) {
    $genderErr = "Select at least one";
  } else {
    $gender = test_input($_POST["gender"]);
  }

 if (empty($_POST["degree"])) {
    $degreeErr = "Degree is required";
  }
  else {

   $degree = $_POST["degree"];
    if(count($degree)<2){
        $degreeErr = "Must select at least two";
    }
  }



   if (empty($_POST["BG"])) {
    $BGErr = "Blood Group is required";
  } else {
    $BG = test_input($_POST["BG"]);
  }


function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}
?>

<h2>PHP Form Validation Example</h2>
<p><span class="error">* required field</span></p>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">  
  Name: <input type="text" name="name">
  <span class="error">* <?php echo $nameErr;?></span>
  <br><br>
  E-mail: <input type="text" name="email">
  <span class="error">* <?php echo $emailErr;?></span>
  <br><br>

  Date of Birth:
  
  <input type ="date" id="DOB" name="DOB">
  <span class="error">* <?php echo $DOBErr;?></span>
  <br><br>

 
  Gender:
  <input type="radio" name="gender" value="female">Female
  <input type="radio" name="gender" value="male">Male
  <input type="radio" name="gender" value="other">Other
  <span class="error">* <?php echo $genderErr;?></span>
  <br><br>
   
  Degree:
  <input type="checkbox" name="degree[]"
      <?php if (isset($degree) && $degree=="SSC") echo "checked";?>
      value="SSC">SSC
      <input type="checkbox" name="degree[]"
      <?php if (isset($degree) && $degree=="HSC") echo "checked";?>
      value="HSC">HSC
      <input type="checkbox" name="degree[]"
      <?php if (isset($degree) && $degree=="BSc") echo "checked";?>
      value="BSc">BSc
      <input type="checkbox" name="degree[]"
      <?php if (isset($degree) && $degree=="MSc") echo "checked";?>
      value="other">MSc
      <span class="error">* <?php echo $degreeErr;?></span>
  <br><br>
   

  Blood Group:

  <select name="BG" id="BG">
    <option value=""></option>
    <option value="A+">A+</option>
    <option value="B+">B+</option>
    <option value="O+">O+</option>
    <option value="AB+">AB+</option>
  </select>
  <span class="error">* <?php echo $BGErr;?></span>
  <br><br>
  <input type="submit" name="submit" value="Submit">
</form>
</form>


<?php
echo "<h2>Your Input:</h2>";
echo $name;
echo "<br>";
echo $email;
echo "<br>";
echo $gender;
echo "<br>";
echo $BG;
echo "<br>";
echo $DOB;

?>

</body>
</html>