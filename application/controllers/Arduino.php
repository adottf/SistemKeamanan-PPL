<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Arduino extends CI_Controller {

	function __construct(){
		parent::__construct();
		$this->load->model('Model_datalog');
	}

	public function index()
	{
		$data = $this->Model_datalog->getData();
	}

	public function insert()
	{
		date_default_timezone_set('Asia/Jakarta');
		
		$inp = $this->input->get();
		$date = date('Y-m-d h:i:s', time());

		$try = $this->Model_datalog->insertLog($date, $inp['logMsg']);
	}
}
