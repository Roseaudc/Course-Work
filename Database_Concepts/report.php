<?php
include "menu.php";
?>
<table border=1>
<tr>
<th>Total Coach Income</th>
</tr>
<?php
include "dbconnect.php";
$sql = "select sum(contract) AS total FROM coach";

$result = myquery($mysqli,$sql);

while($row = $result->fetch_assoc()) {
  echo "<tr>";
  echo '<td>' . '$' . $row['total'] . '</td>';
  echo "</tr>";
}
?>
</table>