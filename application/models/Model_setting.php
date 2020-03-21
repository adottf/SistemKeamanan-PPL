<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Model_setting extends CI_model {

public function save()
 {
  $pass = md5($this->input->post('newpass'));
  $data = array (
   'Password' => $pass
   );
  $this->db->where('Username', $this->session->userdata('Username'));
  $this->db->update('user', $data);
 }
 public function cek()
  {
   $cek = md5($this->input->post('oldpass'));  
   $this->db->where('Password',$cek);
   $query = $this->db->get('user');
      return $query->result();;
          }

}
