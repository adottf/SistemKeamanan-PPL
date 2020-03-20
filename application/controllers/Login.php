<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Login extends CI_Controller {


	public function index()
	{
		$this->load->view('v_login');
	}

	public function getlogin()
	{
		$username = $this->input->post('username');
		$password = $this->input->post('password');

		$this->load->model('model_login');
		$this->model_login->getlogin($username,$password);
	}
}
