<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Setting extends CI_Controller {


	public function index()
	{
		$this->model_security->protokol();
		$this->load->view('v_setting');
	}
	public function logout()
{
	$this->session->sess_destroy();
	redirect('login');
}
}
