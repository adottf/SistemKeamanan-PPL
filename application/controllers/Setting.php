<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Setting extends CI_Controller {


	public function index()
	{
		$this->model_secure->protokol();
		$this->load->view('v_setting');
	}

	public function logout()
{
	$this->session->sess_destroy();
	redirect('login');
}

public function gantipass(){
		$this->form_validation->set_rules('newpass','Newpass','required|trim|matches[validpass]');
  		$this->form_validation->set_rules('validpass', 'Validpass', 'required|trim|matches[newpass]');
    if($this->form_validation->run() == FALSE)
  {
		$this->load->view('v_setting');

  }else{
   $cek = $this->model_setting->cek();
   if ($cek == False){
    $this->session->set_flashdata('error','Old password not match!' );
		$this->load->view('v_setting');
   }else{
    $this->model_setting->save();
    $this->session->sess_destroy();
    $this->session->set_flashdata('error','Your password success to change, please relogin !' );

		redirect('login');
   }//end if valid_user
  }
	}


}
