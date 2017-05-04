<?php
include "menu.php";
?>
<table border=1>

<tr>
<th>Coach's Name</th>
<th>Team Name</th>
<th>Contract Amount</th>

</tr>
<?php
include "dbconnect.php";
$sql = "select * from coach order by name";

$result = myquery($mysqli,$sql);

while($row = $result->fetch_assoc()) {
  echo "<tr>";
  echo '<td>' . $row['name'] . '</td>';
  echo '<td>' . $row['team'] . '</td>';
  echo '<td>' . '$' . $row['contract'] . '</td>';
  echo "<td><a href='delCoachsrv.php?id=" . $row['id'] ."'>Del</a> ";
  echo "<a href='editCoachclt.php?id=" . $row['id']   ."'>Edit</a></td>";
  echo "</tr>";
}
?>
</table>
<a href="addCoachclt.php">Add New Coach</a>