import logging


def setup_logger():
    logging.basicConfig(level=logging.INFO,
                        format="%(levelname)s == %(message)s ==  %(funcName)s == %(lineno)d",
                        handlers=[
                            logging.FileHandler("Matrix.log"),
                            logging.StreamHandler()
                        ])