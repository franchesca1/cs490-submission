<?php
require "vendor/autoload.php";

#connect to mongo client
$client = new Mongo\Client();

#select dtaabase
$db = $client -> employee;

#select table/collection
$collection = $db -> person;

$result = $collection ->find([]);

foreach($result as $row){
    for($row as $key=>$value){
        echo "$key => $value \n"
    
    }
}