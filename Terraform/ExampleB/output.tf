output "os_image_id" {
  value       = "hello world ${data.huaweicloud_images_image_v2.os.id}"
  sensitive   = false
  description = "description"
  depends_on  = []
}

output "var_HW_ACCESS_KEY" {
  value       = "${data.var.access_key.id}"
  sensitive   = false
  description = "description"
  depends_on  = []
}
