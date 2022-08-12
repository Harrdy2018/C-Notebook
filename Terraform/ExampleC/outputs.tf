output "test_path1" {
  value = "${path.cwd}/kubeconfig"
}

output "test_path2" {
  value = "${path.module}/kubeconfig"
}