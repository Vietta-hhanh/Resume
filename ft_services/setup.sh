#/bin/bash
minikube delete
minikube --driver=virtualbox --memory='3000' --disk-size 40000MB start
minikube addons enable metallb
kubectl apply -f ./srcs/loadconfig.yaml
eval $(minikube docker-env)
docker build -t influxdb ./srcs/influxdb
kubectl apply -f ./srcs/influxdb/influxdb.yaml
docker build -t mysql ./srcs/mysql/
kubectl apply -f ./srcs/mysql/mysql.yaml
docker build -t phpmyadmin ./srcs/phpmyadmin
kubectl apply -f ./srcs/phpmyadmin/phpmyadmin.yaml
docker build -t wordpress ./srcs/wordpress
kubectl apply -f ./srcs/wordpress/wordpress.yaml
docker build -t nginx ./srcs/nginx
kubectl apply -f ./srcs/nginx/nginx.yaml
docker build -t ftps ./srcs/ftps
kubectl apply -f ./srcs/ftps/ftps.yaml
docker build -t grafana ./srcs/grafana
kubectl apply -f ./srcs/grafana/grafana.yaml
echo КОНЕЦ ВСЕМ МУЧЕНИЯМ :/