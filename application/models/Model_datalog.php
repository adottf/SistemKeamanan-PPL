<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Model_datalog extends CI_model {
    public function getData()
	{
        $data = $this->db->query("SELECT * from data_log");
        return $data->result_array();
    }

    public function insertLog($time, $info)
    {
        $query = "INSERT INTO data_log(waktu, kondisi) VALUES ('".$time."', '".$info."');";

        return $this->db->query($query);
    }
        
}
