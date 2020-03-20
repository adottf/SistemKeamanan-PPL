<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Home extends CI_Controller {

public function index()
	{

		$this->model_secure->protokol();
		
        $this->load->view('v_home');
	}

public function logout()
{
	$this->session->sess_destroy();
	redirect('login');
}

}