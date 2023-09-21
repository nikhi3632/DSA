COMPILER = python3
TEST_FILE ?= test.txt

prims:
	$(COMPILER) main.py $(TEST_FILE) prims 2>&1 | tee prims.log

kruskals:
	$(COMPILER) main.py $(TEST_FILE) kruskals 2>&1 | tee kruskals.log

run:
	$(COMPILER) main.py $(TEST_FILE) run 2>&1 | tee run.log	

tidy:
	rm -rf __pycache__ prims.log kruskals.log

clean:
	rm -rf *log __pycache__