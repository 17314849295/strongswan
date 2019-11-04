/*
 * Copyright (C) 2015 Martin Willi
 * Copyright (C) 2015 revosec AG
 *
 * Copyright (C) 2019 Andreas Steffen
 * HSR Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the Licenseor (at your
 * option) any later version. See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be usefulbut
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */

#include <crypto/crypto_tester.h>

/**
 * From RFC 7748
 */
ke_test_vector_t curve25519_1 = {
	.method = CURVE_25519,
	.seed = chunk_from_chars(
		0x77, 0x07, 0x6d, 0x0a, 0x73, 0x18, 0xa5, 0x7d, 0x3c, 0x16,
		0xc1, 0x72, 0x51, 0xb2, 0x66, 0x45, 0xdf, 0x4c, 0x2f, 0x87,
		0xeb, 0xc0, 0x99, 0x2a, 0xb1, 0x77, 0xfb, 0xa5, 0x1d, 0xb9,
		0x2c, 0x2a, /* - */
		0x5d, 0xab, 0x08, 0x7e, 0x62, 0x4a, 0x8a, 0x4b, 0x79, 0xe1,
		0x7f, 0x8b, 0x83, 0x80, 0x0e, 0xe6, 0x6f, 0x3b, 0xb1, 0x29,
		0x26, 0x18, 0xb6, 0xfd, 0x1c, 0x2f, 0x8b, 0x27, 0xff, 0x88,
		0xe0, 0xeb),
	.pub_i = chunk_from_chars(
		0x85, 0x20, 0xf0, 0x09, 0x89, 0x30, 0xa7, 0x54, 0x74, 0x8b,
		0x7d, 0xdc, 0xb4, 0x3e, 0xf7, 0x5a, 0x0d, 0xbf, 0x3a, 0x0d,
		0x26, 0x38, 0x1a, 0xf4, 0xeb, 0xa4, 0xa9, 0x8e, 0xaa, 0x9b,
		0x4e, 0x6a),
	.pub_r = chunk_from_chars(
		0xde, 0x9e, 0xdb, 0x7d, 0x7b, 0x7d, 0xc1, 0xb4, 0xd3, 0x5b,
		0x61, 0xc2, 0xec, 0xe4, 0x35, 0x37, 0x3f, 0x83, 0x43, 0xc8,
		0x5b, 0x78, 0x67, 0x4d, 0xad, 0xfc, 0x7e, 0x14, 0x6f, 0x88,
		0x2b, 0x4f),
	.shared = chunk_from_chars(
		0x4a, 0x5d, 0x9d, 0x5b, 0xa4, 0xce, 0x2d, 0xe1, 0x72, 0x8e,
		0x3b, 0xf4, 0x80, 0x35, 0x0f, 0x25, 0xe0, 0x7e, 0x21, 0xc9,
		0x47, 0xd1, 0x9e, 0x33, 0x76, 0xf0, 0x9b, 0x3c, 0x1e, 0x16,
		0x17, 0x42)
};

/**
 * From RFC 8031
 */
ke_test_vector_t curve25519_2 = {
	.method = CURVE_25519,
	.seed = chunk_from_chars(
		0x75, 0x1f, 0xb4, 0x30, 0x86, 0x55, 0xb4, 0x76, 0xb6, 0x78,
		0x9b, 0x73, 0x25, 0xf9, 0xea, 0x8c, 0xdd, 0xd1, 0x6a, 0x58,
		0x53, 0x3f, 0xf6, 0xd9, 0xe6, 0x00, 0x09, 0x46, 0x4a, 0x5f,
		0x9d, 0x94, /* - */
		0x0a, 0x54, 0x64, 0x52, 0x53, 0x29, 0x0d, 0x60, 0xdd, 0xad,
		0xd0, 0xe0, 0x30, 0xba, 0xcd, 0x9e, 0x55, 0x01, 0xef, 0xdc,
		0x22, 0x07, 0x55, 0xa1, 0xe9, 0x78, 0xf1, 0xb8, 0x39, 0xa0,
		0x56, 0x88),
	.pub_i = chunk_from_chars(
		0x48, 0xd5, 0xdd, 0xd4, 0x06, 0x12, 0x57, 0xba, 0x16, 0x6f,
		0xa3, 0xf9, 0xbb, 0xdb, 0x74, 0xf1, 0xa4, 0xe8, 0x1c, 0x08,
		0x93, 0x84, 0xfa, 0x77, 0xf7, 0x90, 0x70, 0x9f, 0x0d, 0xfb,
		0xc7, 0x66),
	.pub_r = chunk_from_chars(
		0x0b, 0xe7, 0xc1, 0xf5, 0xaa, 0xd8, 0x7d, 0x7e, 0x44, 0x86,
		0x62, 0x67, 0x32, 0x98, 0xa4, 0x43, 0x47, 0x8b, 0x85, 0x97,
		0x45, 0x17, 0x9e, 0xaf, 0x56, 0x4c, 0x79, 0xc0, 0xef, 0x6e,
		0xee, 0x25),
	.shared = chunk_from_chars(
		0xc7, 0x49, 0x50, 0x60, 0x7a, 0x12, 0x32, 0x7f, 0x32, 0x04,
		0xd9, 0x4b, 0x68, 0x25, 0xbf, 0xb0, 0x68, 0xb7, 0xf8, 0x31,
		0x9a, 0x9e, 0x37, 0x08, 0xed, 0x3d, 0x43, 0xce, 0x81, 0x30,
		0xc9, 0x50)
};
