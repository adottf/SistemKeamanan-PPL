<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Index extends CI_Controller {
    public function __construct()
    {
		parent::__construct();
	}

	function index()
	{
        
        $this->load->view('home');
	}
	function login()
	{
        
        $this->load->view('login');
	}
	function daftar()
	{
        
        $this->load->view('daftar');
	}
}