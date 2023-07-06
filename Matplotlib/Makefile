run:
	@echo "Inserte contraseña para instalar python y sus dependencias"
	@rm -rf lib/__pycache__
	@sudo apt install python3
	@pip install pandas
	@pip install numpy
	@pip install matplotlib
	@python3 main.py
	
.PHONY: clean
clean:
	@rm -rf lib/__pycache__
