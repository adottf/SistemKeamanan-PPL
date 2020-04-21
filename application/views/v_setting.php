<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta name="description" content="">
    <meta name="keywords" content="">
    <title>Wisma Arum | Sistem Informasi Monitoring</title>
    <!-- Favicon -->
    <link href="#" rel="shortcut icon">
    <!-- CSS -->
    <link href="<?php echo base_url() ?>assets/plugins/bootstrap/bootstrap.min.css" rel="stylesheet">
    <link href="<?php echo base_url() ?>assets/plugins/owl-carousel/owl.carousel.min.css" rel="stylesheet">
    <link href="<?php echo base_url() ?>assets/plugins/owl-carousel/owl.theme.default.min.css" rel="stylesheet">
    <link href="<?php echo base_url() ?>assets/plugins/magnific-popup/magnific-popup.min.css" rel="stylesheet">
    <link href="<?php echo base_url() ?>assets/css/app.min.css" rel="stylesheet">
    <!-- Fonts/Icons -->
    <link href="<?php echo base_url() ?>assets/plugins/font-awesome/css/all.css" rel="stylesheet">
    <link href="<?php echo base_url() ?>assets/plugins/themify/themify-icons.min.css" rel="stylesheet">
</head>

<body data-preloader="2">

    <header>
        <nav class="navbar navbar-white navbar-absolute navbar-fixed">
            <div class="container">
                <a class="navbar-brand" href="#">
                    <h6 class="line-height-100">
                        <font color="#00000">Wisma Arum <br>
                            <font size="2" class="font-weight-light">Sistem Informasi Monitoring</font>
                        </font>
                    </h6>

                </a>

                <button class="fullscreen-toggle-btn">
                    <span class="lines" color="#00000"></span>
                </button>
                <!-- Nav Toggle button -->

            </div><!-- end container -->
        </nav>
        <!-- end nav -->
        <div class="fullscreen-menu bg-white">
            <!-- Add your background class here -->
            <div class="fullscreen-menu-wrapper">
                <div class="position-middle">
                    <div class="container">
                        <div class="row">
                            <div class="col-12 col-md-10 offset-md-1 col-lg-8 offset-lg-2">
                                <div class="row">
                                    <div class="col-12 col-md-6">
                                        <ul class="list-unstyled">
                                            <li>
                                                <h6 class="font-weight-normal uppercase letter-spacing-2px"><a
                                                        class="hyperlink-7" href="<?php echo base_url() ?>home">Dashboard</a></h6>
                                            </li>
                                            <li>
                                                <h6 class="font-weight-normal uppercase letter-spacing-2px"><a
                                                        class="hyperlink-7" href="<?php echo base_url()?>Arduino">Arduino</a></h6>
                                            </li>
                                            <li>
                                                <h6 class="font-weight-normal uppercase letter-spacing-2px"><a
                                                        class="hyperlink-7" href="<?php echo base_url() ?>setting">Setting</a>
                                                </h6>
                                            </li>
                                             <li>
                                                <h6 class="font-weight-normal uppercase letter-spacing-2px"><a
                                                        class="hyperlink-7" href="<?php echo base_url() ?>setting/logout">Logout</a>
                                                </h6>
                                            </li>
                                        </ul>
                                    </div>
                                    <div class="col-12 col-md-6">
                                        <h5 class="font-weight-normal">Contact Info:</h5>
                                        <ul class="list-unstyled">
                                            <li>support@domain.com</li>
                                            <li>+6281 2345 6789</li>
                                            <li>Jl Kelengkeng Raya, Umbul Natim, Way Huwi, Jati Agung, Lampung Selatan,
                                                Lampung</li>
                                        </ul>
                                        <ul class="list-horizontal-unstyled icon-sm margin-top-20">
                                            <li><a class="button-circle button-circle-sm button-border-1px button-circle-outline-white"
                                                    href="#"><i class="fab fa-facebook-f"></i></a></li>
                                            <li><a class="button-circle button-circle-sm button-border-1px button-circle-outline-white"
                                                    href="#"><i class="fab fa-twitter"></i></a></li>
                                            <li><a class="button-circle button-circle-sm button-border-1px button-circle-outline-white"
                                                    href="#"><i class="fab fa-instagram"></i></a></li>
                                        </ul>
                                    </div>
                                </div><!-- end row(inner) -->
                            </div>
                        </div><!-- end row(outer) -->
                    </div><!-- end container -->
                </div><!-- end position-middle -->
            </div><!-- end fullscreen-menu-wrapper -->
        </div>
    </header>

    <!-- Scroll to top button -->
    <div class="scrolltotop">
        <a class="button-circle button-circle-sm button-circle-dark" href="#"><i class="ti-arrow-up"></i></a>
    </div>
    <!-- end Scroll to top button -->

    <!-- Home section -->
    <div class="bg-image parallax" style="background-image: url(<?php echo base_url() ?>assets/images/bg-wisma.jpg)">
        <div class="section">
            <div class="container">
                <div class="row justify-content-md-center">
                    <div class="col-md-5">
                        <form action="<?php echo base_url() ?>setting/gantipass" method="post" class="bg-white p-md-5 p-4 mb-5 border" onSubmit="return validatePassword()">
                            <h2 class="font-weight-bold" align="center">Ubah Password</h2><br>
                            <hr width="100%" align="center">
                            <div align="center"><?php echo $this->session->flashdata('error'); ?></div>
                           
                            <div class="form-group">
                                <label class="text-black font-weight-bold" for="email">Password Lama</label>
                                <input type="password" name="oldpass" id="oldpass" class="txtField" placeholder="Masukkan password lama" value="<?php echo set_value('oldpass');?>"/>
                            </div>
                            <div class="form-group">
                                <label class="text-black font-weight-bold" for="email">Password Baru</label>
                                <input type="password" name="newpass" id="newpass" class="txtField"
                                    placeholder="Masukkan password baru" value="<?php echo set_value('newpass');?>" />
                            </div>
                            <div class="form-group">
                                <label class="text-black font-weight-bold" for="password">Konfirmasi Password</label>
                                <input type="password" name="validpass" id="validpass" class="txtField"
                                    placeholder="Konfirmasi password baru" value="<?php echo set_value('validpass');?>" />
                            </div>
                            <div class="form-group" align="center">
                                <td colspan="2">
                                    <a href="<?php echo base_url() ?>home"><button class="button button-lg button-lg button-reveal-right-dark button-rounded button-border-1px margin-top-30 scrolldown">
                                        Batal &nbsp; <i class="ti-arrow-right"></i></button></a>&nbsp;&nbsp;
                                        
                                    <button type="submit" class="button button-lg button-lg button-reveal-right-dark button-rounded button-border-1px margin-top-30 scrolldown" >Simpan &nbsp; <i class="ti-arrow-right"></i></button>
                                </td>
                            </div>
                        </form>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <!-- end Home section -->

    <!-- Validaton -->
    <script>
        function validatePassword() {
            var oldpass, newpass, validpass, output = true;

            oldpass = document.frmChange.oldpass;
            newpass = document.frmChange.newpass;
            validpass = document.frmChange.validpass;

            if (!oldpass.value) {
                oldpass.focus();
                document.getElementById("oldpass").innerHTML = "required";
                output = false;
            } else if (!newpass.value) {
                newpass.focus();
                document.getElementById("newpass").innerHTML = "required";
                output = false;
            } else if (!validpass.value) {
                validpass.focus();
                document.getElementById("validpass").innerHTML = "required";
                output = false;
            }
            if (newpass.value != validpass.value) {
                newpass.value = "";
                validpass.value = "";
                newpass.focus();
                document.getElementById("validpass").innerHTML = "not same";
                output = false;
            }
            return output;
        }
    </script>
    <!-- end Validation -->

    <footer>
        <div class="footer bg-dark">
            <div class="container">
                <div class="row col-spacing-40">
                    <div class="col-12 col-md-6 col-lg-3">
                        <img src="<?php echo base_url() ?>assets/images/boarding_icon.png" alt="wisma">
                    </div>
                    <div class="col-12 col-md-6 col-lg-3">
                        <h6 class="heading-uppercase">Wisma Arum</h6>
                        <ul class="list-dash">
                            <li><a href="#">Tentang wisma arum</a></li>
                        </ul>
                    </div>
                    <div class="col-12 col-md-6 col-lg-3">
                        <h6 class="heading-uppercase">Hubungi Kami</h6>
                        <ul class="list-unstyled">
                            <li>Jl Kelengkeng Raya, Umbul Natim, Way Huwi, Jati Agung, Lampung Selatan, Lampung</li>
                            <li>support@domain.com</li>
                            <li>+(62)812 3456 789</li>
                        </ul>
                    </div>
                </div><!-- end row(1) -->

                <hr class="margin-top-50 margin-bottom-30">

                <div class="row">
                    <div class="col-12 col-md-6 text-center text-md-left">
                        <p>&copy; 2019 Wisma Arum, All Rights Reserved.</p>
                    </div>
                    <div class="col-12 col-md-6 text-center text-md-right">
                        <ul class="list-horizontal-unstyled">
                            <li><a href="#"><i class="fab fa-facebook-f"></i></a></li>
                            <li><a href="#"><i class="fab fa-twitter"></i></a></li>
                            <li><a href="#"><i class="fab fa-instagram"></i></a></li>
                        </ul>
                    </div>
                </div><!-- end row(2) -->
            </div><!-- end container -->
        </div><!-- end footer -->
    </footer>

    <!-- ***** JAVASCRIPTS ***** -->
    <!-- Libraries -->
    <script src="<?php echo base_url() ?>assets/plugins/jquery.min.js"></script>
    <script src="<?php echo base_url() ?>assets/plugins/bootstrap/popper.min.js"></script>
    <!-- Plugins -->
    <script src="<?php echo base_url() ?>assets/plugins/bootstrap/bootstrap.min.js"></script>
    <script src="<?php echo base_url() ?>assets/plugins/appear.min.js"></script>
    <script src="<?php echo base_url() ?>assets/plugins/easing.min.js"></script>
    <script src="<?php echo base_url() ?>assets/plugins/retina.min.js"></script>
    <script src="<?php echo base_url() ?>assets/plugins/countdown.min.js"></script>
    <script src="<?php echo base_url() ?>assets/plugins/imagesloaded.pkgd.min.js"></script>
    <script src="<?php echo base_url() ?>assets/plugins/isotope.pkgd.min.js"></script>
    <script src="<?php echo base_url() ?>assets/plugins/jarallax/jarallax.min.js"></script>
    <script src="<?php echo base_url() ?>assets/plugins/jarallax/jarallax-video.min.js"></script>
    <script src="<?php echo base_url() ?>assets/plugins/magnific-popup/magnific-popup.min.js"></script>
    <script src="<?php echo base_url() ?>assets/plugins/owl-carousel/owl.carousel.min.js"></script>
    <script src="<?php echo base_url() ?>assets/plugins/jquery.easypiechart.min.js"></script>
    <script src="<?php echo base_url() ?>assets/plugins/gmaps.min.js"></script>
    <!-- Scripts -->
    <script src="<?php echo base_url() ?>assets/js/functions.min.js"></script>

</body>

</html>