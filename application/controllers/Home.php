<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Home extends CI_Controller {

	function __construct(){
		parent::__construct();
		$this->load->model('Model_datalog');
	}

	public function index()
	{
		$this->model_secure->protokol();

		$data['data'] = $this->Model_datalog->getData();
		
		$this->load->view('v_home', $data);
	}

	public function logout()
	{
		$this->session->sess_destroy();
		redirect('login');
	}

}