variable "hw_access_key" {
  type        = string
  default     = ""
  description = "description hw_access_key"
}

variable "hw_secret_key" {
  type        = string
  default     = ""
  description = "description hw_secret_key"
}

variable "hw_region" {
  type        = string
  default     = "cn-east-3"
  description = "description hw_region"
}

variable "hw_az" {
  type        = string
  default     = "cn-east-az"
  description = "description hw_az"
}

variable "flavor_name" {
  type        = string
  default     = "t6.small.1"
  description = "description flavor_name"
}

variable "image_name" {
  type        = string
  default     = "CentOS 7.6 64bit"
  description = "description image_name"
}