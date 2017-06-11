
(cl:in-package :asdf)

(defsystem "ros_drone-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "gps_service" :depends-on ("_package_gps_service"))
    (:file "_package_gps_service" :depends-on ("_package"))
  ))