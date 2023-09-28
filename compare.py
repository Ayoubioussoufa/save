def compare_binary_files(file1_path, file2_path, output_file):
    with open(file1_path, 'rb') as file1, open(file2_path, 'rb') as file2, open(output_file, 'wb') as output:
        byte_position = 0
        while True:
            byte1 = file1.read(1)
            byte2 = file2.read(1)

            if not byte1 and not byte2:
                # Both files have reached the end, and there are no differences.
                output.write("Files are identical.".encode())
                break

            if byte1 != byte2:
                # Files differ at this byte position.
                output.write(f"Difference at byte position {byte_position}:\n".encode())

                # Print everything before the difference.
                # file1.seek(-byte_position, 1)
                # file2.seek(-byte_position, 1)
                # context1 = file1.read(byte_position)
                # context2 = file2.read(byte_position)
                # output.write(f"File 1 Context Before: {context1.hex()}\n".encode())
                # output.write(f"File 2 Context Before: {context2.hex()}\n".encode())

                output.write(f"File 1: {byte1.hex()}\n".encode())
                output.write(f"File 2: {byte2.hex()}\n".encode())

                # Print the 10 bytes after the difference.
                context1 = file1.read(10)
                context2 = file2.read(10)
                output.write(f"File 1 Context After: {context1.hex()}\n".encode())
                output.write(f"File 2 Context After: {context2.hex()}\n".encode())

                # Print the last 20 bytes of both files.
                file1.seek(-200, 2)
                file2.seek(-200, 2)
                last_200_bytes_file1 = file1.read()
                last_200_bytes_file2 = file2.read()
                output.write(f"Last 20 Bytes of File 1: {last_200_bytes_file1.hex()}\n".encode())
                output.write(f"Last 20 Bytes of File 2: {last_200_bytes_file2.hex()}\n".encode())
                break

            byte_position += 1

if __name__ == "__main__":
    file1_path = "/nfs/sgoinfre/goinfre/Perso/aybiouss/bJRJIWOTDN"  # Replace with the path to your first binary file
    file2_path = "/nfs/sgoinfre/goinfre/Perso/aybiouss/vid"  # Replace with the path to your second binary file
    output_file = "/nfs/homes/aybiouss/Desktop/web-server/output.txt"  # Replace with the desired output file path

    compare_binary_files(file1_path, file2_path, output_file)
