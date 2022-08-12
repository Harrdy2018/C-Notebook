data "template_file" "init" {
  template = "${file("${path.cwd}/modules/users/init.tpl")}"
  vars = {
    name = "${var.username}"
    age = 444
    consul_host = "${var.consul_host}"
    platform ="mobile"
  }
}