<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Model_secure extends CI_model {

public function protokol()
	{
                $Username = $this->session->userdata('Username');
                if(empty($Username)){
                        $this->session->sess_destroy();
                        redirect('login');
                }
        }

}
