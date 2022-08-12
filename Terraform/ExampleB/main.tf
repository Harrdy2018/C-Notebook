terraform {
  required_providers {
    huaweicloud = {
      source  = "huaweicloud/huaweicloud"
      version = "~> 1.26.0"
    }
  }
}

# Configure the HuaweiCloud Provider
provider "huaweicloud" {
    auth_url = "https://iam.myhwclouds.com/v3"
    insecure = "false"
    region = "cn-east-3"
    access_key = "CVUKUKFGHZCVC3VICRHL"
    secret_key = "WRWtrgck6CWGShJRX7pTJ9GYSq3PhNapjt2x6lhz"
}

data "huaweicloud_images_image_v2" "os" {
    name = "${var.image_name}"
    most_recent = true
}

data "var" "access_key" {
    id = "${var.hw_access_key}"
}