<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Model_login extends CI_model {

public function getlogin($username, $password)
	{
        $pwd=md5($password);
        $this->db->where('Username',$username);
        $this->db->where('Password',$pwd);
        $this->db->reconnect();
        $query = $this->db->get('user');
        if ($query->num_rows()>0) {
        	
        		foreach ($query->result() as $row) {
        				$session = array('Username' =>  $row->Username,
        								'Password'=> $row->Password );
        				$this->session->set_userdata($session);
        				redirect('home');
        			}
        			$this->db->reconnect();	
        	
        
	} else {
		$this->session->set_flashdata('msg','<div class="alert alert-danger text-center">Maaf Email atau Password salah!</div>');
		redirect('login');
		$this->db->reconnect();
	}
}
}
